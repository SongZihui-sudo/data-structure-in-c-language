add_rules("mode.debug", "mode.release")

target("Astar")
    set_kind("binary")
    add_files("src/*.cc")
target_end()

target("test")
    set_kind("binary")
    add_files("src/test/*.cc","src/A-star.cc")
target_end()
