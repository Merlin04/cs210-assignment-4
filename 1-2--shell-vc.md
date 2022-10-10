a. I'd make sure that the executable is in my PATH, either by symlinking it into some directory like ~/bin that I've already added, or by adding the folder with the binary to my PATH (method depends on shell, I use xonsh so I'd add it by putting `$PATH.add("~/insert-path-here")` to my `.xonshrc`)
b. Here's my `.xonshrc`, I accidentally overwrote it while working on it so I had to recover bits of it from a shell session that was open from before I made the mistake!

```python
xontrib load fish_completer vox voxapi xog whole_word_jumping cmd_done
$XONTRIB_CD_LONG_DURATION=10
$PATH.add("~/.local/bin")
$PATH.add("~/bin")
$PATH.add("~/.bun/bin")
$PATH.add("~/.yarn/bin")
$PROMPT = '{PURPLE}{user}{RESET}|{CYAN}{cwd}{RESET}{env_name}{curr_branch: {}}> '
```

Probably the most important part of this is adding various directories to my path (like the one for the Node.js package manager `yarn`). There's also a custom prompt and various xontribs (plugins) for features like better autocomplete and whole word jumping with ctrl-arrowkey.

c. `cat Logistics.tex | head -n 50 | grep -o that | wc -l`
