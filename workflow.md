# Workflow

This is my workflow for editing my QMK keymaps.

## Setup

* [Set up QMK](https://docs.qmk.fm/#/getting_started_build_tools).
* Open the QMK shell and navigate to the home folder (~/qmk_firmware).
* Add the remote: `git remote add object-Object https://github.com/object-Object/qmk_firmware`
* Pull: `git pull`

## Usage

* Open the QMK shell and navigate to the home folder (~/qmk_firmware).
* Checkout the branch: `git checkout object-Object/stable`
* Add, stage, and commit files.

## Updating

* `git checkout master`
* `git pull`
* `git checkout object-Object/stable`
* `git rebase master`

For more info, [see this link](https://erovia.github.io/posts/workflow/).
