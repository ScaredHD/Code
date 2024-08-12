#lang sicp

(#%require (only racket provide all-defined-out))

(provide (all-defined-out))

(define (square x) (* x x))

(define (length seq)
  (if (null? seq)
      0
      (+ 1 (length (cdr seq)))))

(define (append a b)
  (if (null? a)
      b
      (cons (car a) (append (cdr a) b))))


(define (map proc seq)
  (if (null? seq)
      nil
      (cons (proc (car seq))
            (map proc (cdr seq)))))

(define (filter pred seq)
  (cond ((null? seq) nil)
        ((pred (car seq))
         (cons (car seq)
               (filter pred (cdr seq))))
        (else (filter pred (cdr seq)))))

(define (accumulate op init seq)
  (if (null? seq)
      init
      (op (car seq)
          (accumulate op init (cdr seq)))))

(define (enumerate lo hi)
  (if (> lo hi)
      nil
      (cons lo (enumerate (inc lo) hi))))

(define (enumerate-leave tree)
  (cond ((null? tree) nil)
        ((not (pair? tree)) (list tree))
        (else (append (enumerate-leave (car tree))
                      (enumerate-leave (cdr tree))))))