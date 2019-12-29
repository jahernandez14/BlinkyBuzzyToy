switches: 
  .word case0
  .word case1
  
advance_state:
  sub #4, r1
  mov state, 0(r1)
  mov 0(r1), r12
  call advance_state
  move inState, 2(r1)
  call led_update
  
case0:
  mov P1OUT LED_RED
  jmp end
  
case1:
  mov p1OUT LED_GREEN
  jmp end
  
end: 
  add #4, r1
  ret
  
