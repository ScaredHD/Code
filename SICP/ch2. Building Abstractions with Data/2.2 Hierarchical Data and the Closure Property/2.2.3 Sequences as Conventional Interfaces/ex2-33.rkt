#lang sicp

(#%require "../../ch2_common.rkt")


; accumulate = right fold
(define (Map f seq)
  (accumulate (lambda (x y) (cons (f x) y)) nil seq))

(map square (list 1 2 3 4 5))
(Map square (list 1 2 3 4 5))

(define (Append seq1 seq2)
  (accumulate cons seq2 seq1))

(Append (list 1 2 3) (list 4 5 6))
(append (list 1 2 3) (list 4 5 6))

(define (Length seq)
  (accumulate (lambda (x y) (+ 1 y)) 0 seq))

(Length (list 1 2 3 4 5))
(length (list 1 2 3 4 5))

