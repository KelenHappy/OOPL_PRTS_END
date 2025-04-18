cmake_minimum_required(VERSION 3.16)
project(PRTS)

set(CMAKE_CXX_STANDARD 17)

cmake_policy(SET CMP0135 NEW)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
    ptsd

    URL         https://github.com/ntut-open-source-club/practical-tools-for-simple-design/archive/refs/tags/v0.2.zip

    # Or alternatively if you want to use a specific git commit instead of a release:
    # GIT_REPOSITORY  https://github.com/ntut-open-source-club/practical-tools-for-simple-design.git
    # GIT_TAG         <git_tag>

    SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/PTSD
)

FetchContent_MakeAvailable(ptsd)

include(files.cmake)
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
list(TRANSFORM SRC_FILES PREPEND ${SRC_DIR}/)
list(TRANSFORM INCLUDE_FILES PREPEND ${INCLUDE_DIR}/)

# file(GLOB_RECURSE SRC_FILES src/*)
# file(GLOB_RECURSE HEADER_FILES include/*)

add_executable(${PROJECT_NAME}
    ${SRC_DIR}/main.cpp
    ${SRC_FILES}
		src/App.cpp
		src/App/AppUpdate.cpp
		src/App/AppStart.cpp
		src/App/AppEnd.cpp
		src/App/AppMap1017.cpp
		src/App/AppMap0107Start.cpp
		src/App/AppGametick.cpp
		src/App/AppSecondTick.cpp
		src/Block.cpp
		src/Card.cpp
		src/Character/AnimatedCharacter.cpp
		src/Enemy/Enemy.cpp
        src/Map.cpp
		src/MobSpawner.cpp
    ${HEADER_FILES}
        include/App.hpp	
		include/Block.hpp
        include/BlockState.hpp
		
		include/Enemy/AnimatedEnemy.hpp
		include/Enemy/Enemy.hpp
		include/Enemy/EnemyState.hpp
		include/Enemy/BugA.hpp
		include/Enemy/Soldier.hpp
		include/Enemy/Thrower.hpp
		include/Enemy/Varlorant.hpp

		include/CreateIMG.hpp
		include/Card.hpp
		include/ClassState.hpp
		include/CharacterType.hpp

		include/GamePlayMode/Attack.hpp
		include/GamePlayMode/CharacterAttackImpact.hpp
		include/GamePlayMode/CharacterSkill.hpp
		include/GamePlayMode/AttackRange.hpp
		
		include/Map.hpp
		include/MainScream.hpp
		
		include/Character/AnimatedCharacter.hpp
		include/Character/CharacterState.hpp
        include/Character/Medic.hpp
		include/Character/Sniper.hpp
		include/Character/Vanguard.hpp
		
		include/Character/Vanguard/Texas.hpp
		include/Character/Vanguard/Ines.hpp
		
		include/Character/Medic/Sussurro.hpp
		include/Character/Sniper/Exudiai.hpp
		
		
		include/TextBox.hpp
		include/ImgItem.hpp
		include/GameTimer.hpp
		include/move.hpp
		include/Pathpoints.hpp
		include/MobSpawner.hpp
		include/Enemy/EnemyType.hpp
		include/MyTool.hpp
		include/Hpbar.hpp
		src/App/APPTool.cpp
		include/FlyUI.hpp


)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/Resources")
else()
    message(FATAL_ERROR "relative RESOURCE_DIR is WIP, Please use `-DCMAKE_BUILD_TYPE=Debug` build for now.")
    target_compile_definitions(${PROJECT_NAME} PRIVATE RESOURCE_DIR="${CMAKE_INSTALL_PREFIX}/Resources")
endif()

target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${DEPENDENCY_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/PTSD/include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
    SDL2::SDL2main
    PTSD
)
