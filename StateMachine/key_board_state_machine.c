#include<stdlib.h>
#include<stdio.h>


enum KBD_STATES{
	SHIFTED,
	DEFAULT,
	MAX_STATES
};

enum KBD_EVENTS{
	SHIFT_DEPRESSED,
	SHIFT_RELEASED,
	MAX_EVENTS
};

int kbd_shifted_depressed(void);
int kbd_shifted_released(void);
int kbd_default_depressed(void);
int kbd_default_released(void);

enum KBD_EVENTS get_new_event();

int (*state_func_table [MAX_STATES][MAX_EVENTS]) (void) = {
 
  {kbd_shifted_depressed, kbd_shifted_released},
  {kbd_default_depressed, kbd_default_released}
};


void main()
{
	enum KBD_EVENTS new_event = get_new_event();
	enum KBD_STATES current_state = DEFAULT; 
	
	for(;;)
	{
	  if (((new_event >= 0) && (new_event < MAX_EVENTS))
      && ((current_state >= 0) && (current_state < MAX_STATES))) 
	  {
        current_state = state_func_table[current_state][new_event]();
		new_event = get_new_event();
	  }
	  else
	  {
	  	#error
	  }
	  
	  
    }
}
