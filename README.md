# 安裝流程
## 編譯原碼  
``` sh
git clone https://github.com/KelenHappy/OOPL_PRTS_END.git  
```
## Resources要去Google Dirve下載  
[點我前往](https://drive.google.com/drive/folders/1dGWjiqmMdWLbofvaHPUsZz9-yQ0pzoZv)  
## 編譯
```sh
cmake -DCMAKE_BUILD_TYPE=Debug -B build # -G Ninja
 ```
better read [PTSD README](https://github.com/ntut-open-source-club/practical-tools-for-simple-design)  

# 工作腳本
## 轉換png
``` sh
ffmpeg -i test.webm -vf "colorkey=0x00FF00:0.3:0.1" -pix_fmt rgba %d.png
```

## 無損壓縮
``` sh
find . -name "*.png" -exec optipng -o7 {} \;
```

## 打包
``` sh
7z a -t7z -mx=9 -m0=LZMA2 -ms=on -md=512m Resources.7z Resources
```

