
#include "Video/WebMPlayer.hpp"
#include <stdexcept>
#include <iostream>
extern "C" {
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>

}

struct WebMPlayer::Impl {
    AVFormatContext* formatCtx = nullptr;
    AVCodecContext* codecCtx = nullptr;
    AVFrame* frame = nullptr;
    AVFrame* frameRGB = nullptr;
    SwsContext* swsCtx = nullptr;
    SDL_Texture* texture = nullptr;
    int videoStreamIndex = -1;
    bool isPlaying = false;
};

WebMPlayer::WebMPlayer() : m_impl(new Impl()) {}

WebMPlayer::~WebMPlayer() {
    if (m_impl->texture) SDL_DestroyTexture(m_impl->texture);
    if (m_impl->frame) av_frame_free(&m_impl->frame);
    if (m_impl->frameRGB) av_frame_free(&m_impl->frameRGB);
    if (m_impl->codecCtx) avcodec_free_context(&m_impl->codecCtx);  //修正這裡
    if (m_impl->formatCtx) avformat_close_input(&m_impl->formatCtx);
    delete m_impl;
}


bool WebMPlayer::Load(const std::string& filePath) {
    // WebM
    if (avformat_open_input(&m_impl->formatCtx, filePath.c_str(), nullptr, nullptr) != 0) {
        std::cout << "Failed to open video file: " << filePath << std::endl;
        return false;
    }

    if (avformat_find_stream_info(m_impl->formatCtx, nullptr) < 0) {
        std::cout << "Unsupported codec" << std::endl;
        return false;
    }

    // code
    for (unsigned int i = 0; i < m_impl->formatCtx->nb_streams; i++) {
        if (m_impl->formatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            m_impl->videoStreamIndex = i;
            break;
        }
    }

    if (m_impl->videoStreamIndex == -1) {
        std::cout << "No video stream found" <<  std::endl;
        return false;
    }

    // Code
    AVCodecParameters* codecParams = m_impl->formatCtx->streams[m_impl->videoStreamIndex]->codecpar;
    const AVCodec* codec = avcodec_find_decoder(codecParams->codec_id);
    if (!codec) {
        std::cout << "Unsupported codec" << std::endl;
        return false;
    }

    m_impl->codecCtx = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(m_impl->codecCtx, codecParams);
    if (avcodec_open2(m_impl->codecCtx, codec, nullptr) < 0) {
        std::cout << "Unsupported codec" << std::endl;
        return false;
    }

    m_impl->frame = av_frame_alloc();
    m_impl->frameRGB = av_frame_alloc();
    return true;
}

void WebMPlayer::Render(SDL_Renderer* renderer) {
    if (!m_impl->texture) {
        //Render
        m_impl->texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA32,
            SDL_TEXTUREACCESS_STREAMING,
            m_impl->codecCtx->width,
            m_impl->codecCtx->height
        );
    }

    // Texture
    SDL_UpdateTexture(
        m_impl->texture,
        nullptr,
        m_impl->frameRGB->data[0],
        m_impl->frameRGB->linesize[0]
    );

    SDL_RenderCopy(renderer, m_impl->texture, nullptr, nullptr);
}
void WebMPlayer::Play() {
    m_impl->isPlaying = true;
    std::cout << "Play called" << std::endl;
    // 你真正的播放邏輯寫這裡
}

void WebMPlayer::Pause() {
    m_impl->isPlaying = false;
    std::cout << "Pause called" << std::endl;
    // 暫停邏輯
}

void WebMPlayer::Stop() {
    m_impl->isPlaying = false;
    std::cout << "Stop called" << std::endl;
    // 停止邏輯，釋放資源等
}
