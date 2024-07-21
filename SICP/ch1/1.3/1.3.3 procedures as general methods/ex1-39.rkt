#lang sicp

(define (cont-frac n d k)
  (define (tail-k i)
    (if (= i k)
        (/ (n k) (d k))
        (/ (n i) (+ (d i) (tail-k (+ i 1))))))
  (tail-k 1))

(define (pow x n)
  (if (= n 0) 1 (* x (pow x (- n 1)))))

(define (tan-cf x k)
  (- (cont-frac
    (lambda (i) (- (pow x i)))
    (lambda (i) (- (* 2 i) 1.0))
    k)))

(tan-cf 1 8)
(tan 1)