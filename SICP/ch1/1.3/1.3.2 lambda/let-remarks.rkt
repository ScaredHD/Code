#lang sicp


; will return 38
; inside let x = 3, so value of let is 33
; outside of let x = 5, value of outermost + is (+ 33 5) = 38
((lambda (x)
   (+ (let ((x 3))
        (+ x (* x 10)))
      x)
   )
 5)

; evaluation of names use variables outside of let
; will return 12
((lambda (x)
   (let ((x 3)
         (y (+ x 2)))  ; x = 2 (value of ouside) so y will be bound to 4
     (* x y)))  ; now x is bound to 3, y is bound to 4
 2)