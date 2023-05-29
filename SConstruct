import os

VariantDir('build', 'tests', duplicate=False)
env = Environment( CPPPATH=['./', './doctest/doctest'] )
env['ENV']['TERM'] = os.environ['TERM'] # Colored output

env.Program("test", ["build/main.cc"])
