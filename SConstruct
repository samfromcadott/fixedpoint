import os

env = Environment( CPPPATH=['./include'] )
env['ENV']['TERM'] = os.environ['TERM'] # Colored output

env.Program("test", ["main.cc"])
