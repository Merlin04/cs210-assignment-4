# 1
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

# 2
a. Ok 
b. `git revert [commit sha]`
c. Branches can be described as separate "copies" of the main repository that branch off at a certain commit and can be merged back in later. They are often useful when multiple features of a project are being worked on at a time, allowing your changes to not be messed up by someone else's who is doing something different. You can create one with `git checkout -b [branch name]`, and switch to an already existing one with `git checkout [branch name]`. You can merge a branch into the one you're currently in with `git merge [branch name]`. In cases where git can't automatically merge the changes, you'll be left with a "merge conflict" where you have to do some parts of the merge manually; git will give you instructions when this occurs on how to resolve it.
