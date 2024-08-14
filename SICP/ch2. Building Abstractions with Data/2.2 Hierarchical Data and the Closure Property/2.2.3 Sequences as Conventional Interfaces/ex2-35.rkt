#lang sicp

(#%require "../../ch2_common.rkt")

(define (count-leaves tree)
  (accumulate + 0 (map (lambda (x) 1) (enumerate-leave tree))))


(count-leaves (list 1 (list 2 3 4) (list 5 6) 7 8))

