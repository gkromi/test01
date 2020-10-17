#### Getting Started
```cmd
git init
::Initiate local git
```
```cmd
git config --local user.name "gkromi"
::Sets local/global username (--local | --global)
```
```cmd
git config --local user.email "<>"
::Sets local/global useremail in case of registered user
```
```cmd
git add README.md
::Add a local README.md
```
```cmd
git status
::See (A)ddition|(R)enamed|(M)odified|(D)eleted files status
```
```cmd
git commit -m "Add README.md file"
::Commit "README.md" file
```
```cmd
git push
::or
git push -u origin master
```
#### Misc

```cmd
git checkout main.c
::Revert Uncommitted Changes
```
```cmd
git mv main.h include/
::Moving a file
```
```cmd
git ls-tree -r HEAD
::Tree list of files
```
```cmd
git diff
::Compares files
```
```cmd
git remote -v
::Checks remote link
```
```cmd
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY
::clone a repo

git remote rm origin
::remove remote

git remote add origin https://github.com/<your_username>/Demo.git
::add a remote repo
```
