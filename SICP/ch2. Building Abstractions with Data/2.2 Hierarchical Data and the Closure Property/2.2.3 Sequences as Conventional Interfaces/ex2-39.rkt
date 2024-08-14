#lang sicp

(#%require "../../ch2_common.rkt")

(define (reverse1 seq)
  (fold-right (lambda (x y) (append y (list x))) nil seq))

(define (reverse2 seq)
  (fold-left (lambda (x y) (cons y x)) nil seq))

(reverse1 (list 1 2 3 4 5))
(reverse2 (list 1 2 3 4 5))