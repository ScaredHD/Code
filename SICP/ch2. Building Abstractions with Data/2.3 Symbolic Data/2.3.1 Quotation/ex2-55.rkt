#lang racket

(car ''abracadabra)  ; prints: 'quote

; ''abracadabra
; = (quote (quote abracadabra))
; = list('quote 'abracadabra)
