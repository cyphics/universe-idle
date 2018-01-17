;;; .dir-locals.el --- Project setups                -*- lexical-binding: t; -*-

;; Copyright (C) 2017

;; Author:  <cyphix@beast>
;; Keywords:

((nil . ((eval . (progn
                   ;; require projectile; the following code will fail
                   ;; without it.
                   (require 'projectile)
                   ;; provide a fake "recent" compilation cmd
                   ;; which will be returned by the function
                   ;; `projectile-compilation-command`
                   (puthash (projectile-project-root)
                            "./compile.sh"
                            projectile-compilation-cmd-map)
                   )))))
