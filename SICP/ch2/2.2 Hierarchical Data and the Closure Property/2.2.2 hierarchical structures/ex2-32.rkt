#lang sicp

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))

(define (subsets s)
  (if (null? s)
      (list nil)
      (let ((rest (subsets (cdr s))))
        (append rest
                (map (lambda (x) (append (list (car s)) x))
                     rest)))))

; example (1 2 3)
; get the first element = 1
; rest = (2 3)
; subsets of rest, SR = (() (2) (3) (2 3))
; merge first element with each subset of SR:
; SR1 = ((1) (1 2) (1 3) (1 2 3))
; SR union SR1:
; result = (() (3) (2) (2 3) (1) (1 3) (1 2) (1 2 3))

(subsets (list 1 2 3))