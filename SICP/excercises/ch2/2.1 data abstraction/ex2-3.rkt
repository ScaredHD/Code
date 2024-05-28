#lang sicp

(define (perimeter rect)
  (* (+ (height rect) (width rect)) 2))

(define (area rect)
  (* (height rect) (width rect)))

; ----- abstraction barrier ----

(define (height rect)
  (let ((max-p (get-max rect))
        (min-p (get-min rect)))
    (- (y-point max-p) (y-point min-p))))


(define (width rect)
  (let ((max-p (get-max rect))
        (min-p (get-min rect)))
    (- (x-point max-p) (x-point min-p))))

; (define (height rect)
;   (get-height (get-size rect)))

; (define (width rect)
;   (get-width (get-size rect)))

; ----- abstraction barrier ----

(define (make-rect min-p max-p)
  (cons min-p max-p))

(define (get-min rect)
  (car rect))

(define (get-max rect)
  (cdr rect))

; -- another implementation --

; (define (make-rect center size)
;   (cons center size))

; (define (get-center rect)
;   (car rect))

; (define (get-size rect)
;   (cdr rect))

; (define (make-size w h)
;   (cons w h))

; (define (get-width size)
;   (car size))

; (define (get-height size)
;   (cdr size))

; ----- abstraction barrier ----

(define (make-point x y)
  (cons x y))

(define (x-point p)
  (car p))

(define (y-point p)
  (cdr p))

; ---- some tests ----

(define p0 (make-point 1 2))
(define p1 (make-point 3 6))
(define rect0 (make-rect p0 p1))

; -- test for another implementation
; (define rect0 (make-rect p0 (make-size 2 4)))

(perimeter rect0)
(area rect0)
