/* 
 * File:   hal_gpio.h
* Author: Elsaied_Ahmed Gad 
 * Created on 10. September 2023, 12:27
 */


#ifndef HAL_GPIO_H
#define	HAL_GPIO_H


/*Section : includes !!!! */

#include"pic18f4620.h" 
#include "../mcal_std_types.h"
#include "../Device_config.h" 
#include "gpio_config.h" 

/*Section : Macros Declaration !!!! */
#define BIT_MASK           (uint_8)1 
#define PORT_PIN_MAX_NUMBER        8 
#define PORT_MAX_NUMBER            5


/*Section : Macros Functions !!!! */

#define HWREG8(_x)   (*((volatile STD_ReturnType *)_x))

#define SET_BIT(REG , BIT_POS)     (REG |= (BIT_MASK<<BIT_POS))
#define CLEARE_BIT(REG , BIT_POS)  (REG &= ~(BIT_MASK<<BIT_POS))
#define TOGGLE_BIT(REG , BIT_POS)  (REG ^= (BIT_MASK<<BIT_POS))
#define READ_BIT(REG , BIT_POS)    ((REG >> BIT_POS) &BIT_MASK)


/*Section : Data TYPES Declaration !!!! */

typedef enum {
    low = 0,    // zero volt
    high        // 5 volt 

}logic_t;

typedef enum {
    output = 0 ,
    input

}direction_t;

typedef enum {
    pin0 = 0 ,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
            
}pin_index_t;

typedef enum {
    portA = 0,
    portB,
    portc,
    portD,
    portE
            
}port_index_t;

typedef struct{
    uint_8 PORT          : 3 ;   /* @ref : port_index_t */
    uint_8 PIN           : 3 ;   /* @ref : port_index_t */
    uint_8 DIRECTION     : 1 ;  /* @ref : port_index_t */
    uint_8 LOGIC         : 1 ;  /* @ref : port_index_t */  
}pin_config_t;


/*Section : Function Declaration !!!! */

STD_ReturnType gpio_pin_direction_intialize(const pin_config_t * pin_config);
STD_ReturnType gpio_pin_direction_status(const pin_config_t * pin_config ,direction_t * direction);
STD_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config ,logic_t logic );
STD_ReturnType gpio_pin_Read_logic(const pin_config_t * pin_config ,logic_t * logic );
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config);

STD_ReturnType gpio_pin_intialize(const pin_config_t * pin_config);

STD_ReturnType gpio_port_direction_intialize(port_index_t port , uint_8 direction) ;
STD_ReturnType gpio_port_get_direction_status(port_index_t port , uint_8 * direction);
STD_ReturnType gpio_port_write_logic(port_index_t port , uint_8 logic);
STD_ReturnType gpio_port_Read_logic(port_index_t port , uint_8 * logic);
STD_ReturnType gpio_port_toggle_logic(port_index_t port );

void Application_Port_initialization (void)  ;


#endif	/* HAL_GPIO_H */

