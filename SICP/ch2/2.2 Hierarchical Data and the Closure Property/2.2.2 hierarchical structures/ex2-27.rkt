#lang sicp

(define (map proc l)
  (if (null? l)
      nil
      (cons (proc (car l))
            (map proc (cdr l)))))

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))

; exercise 2.18
(define (reverse l)
  (if (null? (cdr l))
      l
      (append (reverse (cdr l)) (cons (car l) nil))))

(define (deep-reverse t)
  (if (pair? t)
      (map deep-reverse (reverse t))
      t))

(define x (list (list 1 2) (list 3 4) (list 5) 6))

x
(reverse x)
(deep-reverse x)