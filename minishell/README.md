## Notes for minishell

- use a struct as a global var:
	- put **copy_env inside & signals

- how to add history and where?

# pipex
- if no infile and/or outfile are defined, need to keep stdin and/or stdout
- if stdin/stdout were changed during process, need to reset them at the end of pipex execution
- << (reads from the stdin until the delimitor is used, delimitor is always directly after the symbol) & >> (appends to the content of the output file instead of replacing it)


# built-ins
- need to copy the env into another **char & use it for:
	- env: if minishell is called again, the SHLVL variable is increased (+1), command shows last executed line at end of file (from history)
	- export: without arguments prints the environment in ascii order (without last executed line, if a var is defined as empty, it's written as follows myvar='') >> bubble sort; if same var name is exported a second time, the first one is replaced by it
	- unset: take them out of env
- exit: if exit is called, the SHLVL variable is decreased (-1) or if 1, the programme is stopped
	- if exit code higher than 255, echo $? displays 0, otherwise it displays the number (p.e. exit 127)
- echo (export hello=4):
	- single quotes: disregard the $ sign, always writes the content
	- double quotes: check if variable exists in env if $, if it doesn't exist disregard whole word
	- double (inner) quotes and single (outer) quotes: ' rules apply to all
	- single (inner) quotes and double (outer) quotes: " rules apply to all
	- double inner and outer quotes (interpreted from left to right):
		>bash-3.2$ echo "$hello00 "$bonjour" quelle belle journee"
		>  quelle belle journee
	- single inner and outer quotes (interpreted from left to right):
		>bash-3.2$ echo '$hello00 '$bonjour' quelle belle journee'
		>$hello00  quelle belle journee


# signals
- possibility to redirect the signals of ^c, ^d, ^\, otherwise they will execute their normal functions

