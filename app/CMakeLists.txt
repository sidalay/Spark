add_executable(Spark
    main.cpp
    cycle.cpp
    render.cpp
)

target_include_directories(Spark PRIVATE 
    internal
)

target_link_libraries(Spark PRIVATE
    impl
)

target_compile_features(Spark PRIVATE cxx_std_20)
target_compile_options(Spark PRIVATE -Wconversion -Wall -Wextra -Wpedantic -Werror)
