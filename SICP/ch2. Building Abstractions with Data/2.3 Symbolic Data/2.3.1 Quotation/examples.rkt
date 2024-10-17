#lang racket

(define a 1)
(define b 2)


(list a b)

(list 'a 'b)

(list 'a b)

(car '(a b c))

(cdr '(a b c))

(define (Memq item x)
  (cond ((null? x) false)
        ((eq? item (car x)) x)
        (else (Memq item (cdr x)))))

(Memq 'apple '(pear banana prune))

(Memq 'apple '(x (apple sause) y apple pear))

