# Workflow

This is my workflow for editing my QMK keymaps.

See also: [this blog post](https://erovia.github.io/posts/workflow/).

## Setup

* [Set up QMK](https://docs.qmk.fm/#/getting_started_build_tools).
* Open the QMK shell and navigate to the home folder (~/qmk_firmware).
* Add the remote: `git remote add object-Object https://github.com/object-Object/qmk_firmware`
* Pull: `git pull`

## Usage

* Open the QMK shell and navigate to the home folder (~/qmk_firmware).
* Checkout the branch: `git checkout object-Object/stable`
* Add, stage, and commit files.
* Compile: `qmk compile` or `qmk flash` or `make redox/rev1:object-Object:avrdude`

## Updating QMK

* `git checkout master`
* `git pull`
* `git checkout object-Object/stable`
* `git rebase master`

## Updating QMK MSYS

* [Install the most recent release](https://github.com/qmk/qmk_distro_msys/releases/latest)
* `qmk config user.hide_welcome=True user.keyboard=redox/rev1 user.keymap=object-Object`
* If the above command doesn't work, edit the path it claims it wrote the config to, and add the following under the `[user]` header:

```ini
hide_welcome = True
keyboard = redox/rev1
keymap = object-Object
```
