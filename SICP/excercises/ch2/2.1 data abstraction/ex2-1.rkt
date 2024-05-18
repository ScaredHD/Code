#lang sicp

(define (gcd a b)
  (if (= b 0) a (gcd b (remainder a b))))

(define (make-rat n d)
  (define (sign x)
    (cond ((> x 0) 1)
          ((= x 0) 0)
          (else -1)))

  (let ((absn (abs n))
        (absd (abs d))
        (sgn (sign (* n d))))
        (define g (gcd absn absd))
    (cond ((> sgn 0) (cons (/ absn g) (/ absd g)))
          ((= sgn 0) (cons 0 1))
          (else (cons (/ absn g) (- (/ absd g)))))))

(define (numer r) (car r))
(define (denom r) (cdr r))


(define (add-rat x y)
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

(define (div-rat x y)
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))

(define (equal-rat? x y)
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))


(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))


(define one-half (make-rat 1 2))
(define one-third (make-rat 1 3))

(print-rat (add-rat one-half one-third))
(print-rat (mul-rat one-half one-third))
(print-rat (add-rat one-third one-third))

(print-rat (make-rat 1 -2))
(print-rat (make-rat -3 -9))
(print-rat (make-rat -4 42))