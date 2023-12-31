cmake_minimum_required(VERSION 3.17)
project(Hippopotamus)

set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_FLAGS "-fsanitize=undefined -fsanitize=leak -fsanitize=address")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Multimedia
        REQUIRED)


set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(
        SOURCES
        engine/entity_manager.cpp
        engine/system_manager.cpp
        engine/coordinator.cpp
        engine/component_manager.cpp
        engine/system.cpp

        utilities/transformation.cpp
        utilities/conversion.cpp
        utilities/collisions.cpp
        utilities/dsu.cpp
        utilities/cache.cpp

        core/connector.cpp
        core/scene.cpp
        core/spawner.cpp
        core/keyboard.cpp
        core/map_generator.cpp
        core/edge.cpp
        core/animation_pack.cpp

        view/controller.cpp
        view/widgets/game_widget.cpp
        view/widgets/game_menu.cpp
        view/widgets/main_menu.cpp
        view/buttons/menu_button.cpp
        view/widgets/settings_menu.cpp
        view/view.cpp
        view/widgets/losing_widget.cpp
        view/widgets/winning_widget.cpp
        view/widgets/custom_widget.cpp
        view/media_player.cpp

        systems/render_system.cpp
        systems/collision_system.cpp
        systems/joystick_system.cpp
        systems/movement_system.cpp
        systems/serialization_system.cpp
        systems/death_system.cpp
        systems/intelligence_system.cpp
        systems/garbage_system.cpp
        systems/artifact_system.cpp
        systems/animation_system.cpp
        systems/state_system.cpp

        main.cpp
)

qt6_add_big_resources(
        SOURCES
        resources/res.qrc
        resources/necromancer.qrc
        resources/door.qrc
        resources/player.qrc
        resources/skeleton.qrc
        resources/wasp.qrc
        resources/buff-up.qrc
        resources/buff-hp.qrc
)

add_executable(${PROJECT_NAME} ${SOURCES} ${APP_ICON_RESOURCE_WINDOWS})


target_link_libraries(${PROJECT_NAME} Qt6::Core)
target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
target_link_libraries(${PROJECT_NAME} Qt6::Multimedia)