#lang sicp

(define (for-each proc l)
  (cond ((null? l) #t)
        (else (proc (car l)) (for-each proc (cdr l)))))

(define a (list 1 2 3 4 5))

(for-each (lambda (x) (newline) (display x)) a)