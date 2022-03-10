cmake_minimum_required(VERSION 3.17)
project(a89_912_1_Cenan_Horea)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "G:/Qt/5.15.2/mingw81_64/lib/cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)
include_directories(.)



add_executable(a89_912_1_Cenan_Horea
        admin_ui.cpp
        admin_ui.h
        CoatValidator.cpp
        CoatValidator.h
        domain.cpp
        domain.h
        main.cpp
        repo.h
        repo_file.h
        repoCsv.cpp
        repoCsv.h
        repoCsvHtml.cpp
        repoCsvHtml.h
        RepoException.h
        repoHtml.cpp
        repoHtml.h
        service.cpp
        service.h
        tests.cpp
        tests.h
        userUi.cpp
        userUi.h
        adminGUI.cpp
        adminGUI.h
        userGUI.cpp
        userGUI.h
        modeGUI.cpp
        modeGUI.h
        appGUI.cpp
        appGUI.h
        CoatTableModel.h
        CoatTableModel.cpp)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})
qt5_use_modules(${PROJECT_NAME} Core)