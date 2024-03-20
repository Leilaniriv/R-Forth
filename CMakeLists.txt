
FetchContent_MakeAvailable(googletest)

# Add executables
add_executable(int_stack_demo
        int_stack_demo.c
        int_stack.c)

# Add main executable
add_executable(main
        main.c
        token.c)