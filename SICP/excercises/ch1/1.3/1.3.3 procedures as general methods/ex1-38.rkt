#lang sicp

(define (cont-frac n d k)
  (define (tail-k i)
    (if (= i k)
        (/ (n k) (d k))
        (/ (n i) (+ (d i) (tail-k (+ i 1))))))
  (tail-k 1))



(define (approx-e k)
  (define (n i) 1.0)
  (define (d i)
    (let ((group (ceiling (/ (- i 1) 3)))
          (index (remainder (- i 1) 3)))
        (cond ((= group 0) 1)
              ((= index 1) (* 2 group))
              (else 1))))
  (+ 2 (cont-frac n d k)))

(approx-e 100)