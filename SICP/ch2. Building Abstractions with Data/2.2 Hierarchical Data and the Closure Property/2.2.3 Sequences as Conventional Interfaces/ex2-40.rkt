#lang sicp

(#%require "../../ch2_common.rkt")

(define (unique-pairs n)
  (accumulate append
              nil
              (map (lambda (i)
                     (map (lambda (j) (list i j))
                          (enumerate 1 (- i 1))))
                   (enumerate 1 n))))


(define (prime-sum? pair)
  (prime? (+ (car pair) (cadr pair))))

(define (make-pair-sum pair)
  (list (car pair) (cadr pair) (+ (car pair) (cadr pair))))

(define (prime-sum-pairs n)
  (map make-pair-sum (filter prime-sum? (unique-pairs n))))

(unique-pairs 5)

(prime-sum-pairs 5)