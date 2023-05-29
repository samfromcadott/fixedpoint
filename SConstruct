import os

env = Environment( CPPPATH=['./boost-test/include'] )
env['ENV']['TERM'] = os.environ['TERM'] # Colored output

env.Program("test", ["main.cc"])
