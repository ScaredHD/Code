#lang sicp

(define (list-ref l n)
  (if (= n 0)
      (car l)
      (list-ref (cdr l) (- n 1))))

(define one-through-four (list 1 2 3 4))

(list-ref one-through-four 0)
(list-ref one-through-four 1)
(list-ref one-through-four 2)
(list-ref one-through-four 3)

(define (length l)
  (if (null? l)
      0
      (+ 1 (length (cdr l)))))

(length one-through-four)

(define (length-iter l)
  (define (count ls n)
    (if (null? ls)
        n
        (count (cdr ls) (+ n 1))))
  (count l 0))

(length-iter one-through-four)

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))

(define squares (list 1 4 9 16))
(define odds (list 1 3 5 7))

(append squares odds)
