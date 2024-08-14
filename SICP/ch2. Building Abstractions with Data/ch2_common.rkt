#lang sicp

(#%require (only racket provide all-defined-out))

(provide (all-defined-out))

(define (smallest-divisor n) (find-divisor n 2))

(define (find-divisor n test-divisor)
  (cond ((> (square test-divisor) n) n)
        ((divides? test-divisor n) test-divisor)
        (else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b) (= (remainder b a) 0))

(define (square x) (* x x))

(define (prime? n) (= n (smallest-divisor n)))

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

(define fold-right accumulate)

(define (fold-left op init seq)
  (define (iter result rest)
    (if (null? rest)
        result
        (iter (op result (car rest))
              (cdr rest))))
  (iter init seq))

(define (enumerate lo hi)
  (if (> lo hi)
      nil
      (cons lo (enumerate (inc lo) hi))))

(define (enumerate-leave tree)
  (cond ((null? tree) nil)
        ((not (pair? tree)) (list tree))
        (else (append (enumerate-leave (car tree))
                      (enumerate-leave (cdr tree))))))

(define (flatmap proc seq)
  (accumulate append nil (map proc seq)))