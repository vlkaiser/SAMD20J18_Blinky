/**
 * \file
 *
 * \brief GPIO Example - Input, Output, logic
 * 
 *	Engineer: Vicki Kaiser
 *	Date: Sept 20, 2019
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * This is a bare minimum user application template.
 *
 * For documentation of the board, go \ref group_common_boards "here" for a link
 * to the board-specific documentation.
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# Minimal main function that starts with a call to system_init()
 * -# Basic setup of GPIO input/output pin configs
 * -# Sets on-board LED to opposite state of button press
 *
 */


#include <asf.h>

void configure_port_pins(void)
{
	struct port_config	configure_port_pin;				//Create an instance of struct port_config that can be used to adjust the configuration of (any) PORT PIN
	port_get_config_defaults(&configure_port_pin);		//populate the struct with the default values

	/* Edit struct with desired values */
	// INPUT PIN: Button
	configure_port_pin.direction = PORT_PIN_DIR_INPUT;			
	configure_port_pin.input_pull - PORT_PIN_PULL_UP;
	port_pin_set_config(BUTTON_0_PIN, &configure_port_pin);		//write config to BUTTON_0_PIN GPIO port

	// OUTPUT PIN: LED that mirrors the state of the button
	configure_port_pin.direction = PORT_PIN_DIR_OUTPUT;
	port_pin_set_config(LED_0_PIN, &configure_port_pin);		//write config to LED_0_PIN GPIO port

}



int main (void)
{
	system_init();
	
	configure_port_pins();	//Configure Port Pins


	while (1) 
	{
		bool pin_state = port_pin_get_input_level(BUTTON_0_PIN);	//Get the state of the button, store it in var
		port_pin_set_output_level(LED_0_PIN, !pin_state);			//set the LED to the opposite (true/false) of the var (state of button)

	}
}
