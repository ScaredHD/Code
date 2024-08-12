#lang sicp

(define (map proc l)
  (if (null? l)
      nil
      (cons (proc (car l))
            (map proc (cdr l)))))

(define (square x) (* x x))

(define (square-list-1 l)
  (if (null? l)
      nil
      (cons (square (car l)) (square-list-1 (cdr l)))))

(define (square-list-2 l)
  (map square l))

(define items (list 1 2 3 4 5 6))

(square-list-1 items)
(square-list-2 items)