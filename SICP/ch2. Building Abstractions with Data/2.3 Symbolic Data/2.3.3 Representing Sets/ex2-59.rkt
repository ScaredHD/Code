#lang racket

(require "sets_as_unordered_lists.rkt")

(define (union s1 s2)
  (cond ((null? s1) s2)
        ((null? s2) s1)
        (else (if (in? (car s1) s2)
                  (union (cdr s1) s2)
                  (union (cdr s1) (adjoin (car s1) s2))))))

(define s1 '(a b c))
(define s2 '(b c d))

(union s1 s2)
(intersection s1 s2)
(in? 'a s1)
(adjoin 42 s1)
s1
s2
