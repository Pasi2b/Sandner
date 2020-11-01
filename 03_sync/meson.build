project('02_sync', 'cpp')
inc_dir = include_directories('include')

src = ['src/account.cpp', 'src/main.cpp']
thread_dep = dependency('threads')

executable('account',
	sources : src,
	dependencies: thread_dep,
	include_directories : inc_dir)
