import os

VariantDir('build', 'tests', duplicate=False)
env = Environment(
	CPPPATH=['./', './doctest/doctest'],
	CXXFLAGS='-O3'
)
env['ENV']['TERM'] = os.environ['TERM'] # Colored output

env.Program("test", ["build/main.cc"])
env.Program("speed_test", ["build/speed_tests.cc"])
