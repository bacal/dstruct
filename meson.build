project('dstruct','c',
        version: '0.01',
        license: 'gplv3',
        default_options: [
            'c_std=gnu99',
            'buildtype=debug'
        ]
)
cc=meson.get_compiler('c')
cc.get_id()
inc_dir = include_directories('include/dstruct/')
dstruct_sources = ['dstruct/src/bst.c',
                   'dstruct/src/llist.c',
                   'dstruct/src/dllist.c',
                   'dstruct/src/stack.c']

libdstruct = shared_library('dstruct',
                            dstruct_sources,
                            version: '0.0.1',
                            include_directories: inc_dir,
                            install: true)

dstruct_lib_dep = declare_dependency(include_directories : inc_dir , link_with: libdstruct)

executable('demo', 'demo.c', dependencies: dstruct_lib_dep)
