/* 
 * File:   hal_gpio.c
 * Author: Elsaied_Ahmed Gad 
 *
 * Created on 09. September 2023, 23:18
 */

/* section : includes */
#include "hal_gpio.h" 

uint_8 *Tris_registers[] = {&TRISA ,&TRISB ,&TRISC ,&TRISD ,&TRISE }; 
uint_8 *Lat_registers[] = {&LATA ,&LATB ,&LATC ,&LATD ,&LATE};
uint_8 *Port_registers[] = {&PORTA ,&PORTB ,&PORTC ,&PORTD ,&PORTE};

/* section : functions definitions (Implementation )*/

/**
 * @breif :initialize the direction of specific pin @ref : direction_t 
 * @param pin_config : pointer to pin configuration @ ref : pin_config_t
 * @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_pin_direction_intialize(const pin_config_t * pin_config){
  
    STD_ReturnType ret = E_OK ;
    if(NULL == pin_config || pin_config->PIN > PORT_PIN_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
        switch(pin_config->DIRECTION){
            case(output):
                CLEARE_BIT(*Tris_registers[pin_config->PORT] , pin_config->PIN) ;
                
                break ;
            case(input):
                SET_BIT(*Tris_registers[pin_config->PORT] , pin_config->PIN);
                
                break ;
            default : 
               ret = E_NOT_OK ;
        }
    }
    
   
    return (ret) ;
    
}
#endif 
/**
 * 
 * @param pin_config : pointer to pin configuration @ ref : pin_config_t
 * @param direction
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_pin_direction_status(const pin_config_t * pin_config ,direction_t * direction){
    
    STD_ReturnType ret = E_OK ;
    if(NULL == pin_config || NULL == direction || pin_config->PIN > PORT_PIN_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
       *direction =  READ_BIT(*Tris_registers[pin_config->PORT] , pin_config->PIN) ;
    
    }
    
    return (ret) ;
}
#endif
/**
 * @brief : 
 * @param pin_config : pointer to pin configuration @ ref : pin_config_t
 * @param logic
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully 
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_pin_write_logic(const pin_config_t * pin_config ,logic_t logic ){
    
    STD_ReturnType ret = E_OK ;
    if(NULL == pin_config || pin_config->PIN > PORT_PIN_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
        switch (logic){
            case (low):
                CLEARE_BIT (*Lat_registers[pin_config->PORT] , pin_config->PIN) ;
                
                break ;
            case (high) :
                SET_BIT (*Lat_registers[pin_config->PORT] , pin_config->PIN) ;
       
                break ;
                
            default :
                 ret = E_NOT_OK ;       
        }
    
    }
    
    
    return (ret) ;
}
#endif
/**
 * 
 * @param pin_config
 * @param logic
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_pin_Read_logic(const pin_config_t * pin_config ,logic_t * logic ){
    
    STD_ReturnType ret = E_OK ;
    if(NULL == pin_config || NULL == logic || pin_config->PIN > PORT_PIN_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
        
        *logic = READ_BIT(*Port_registers[pin_config->PORT] , pin_config->PIN);

    
    }
    
    return (ret) ;
}
#endif
/**
 * 
 * @param pin_config
@return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_pin_toggle_logic(const pin_config_t * pin_config){
    
    STD_ReturnType ret = E_OK ;
    if(NULL == pin_config || pin_config->PIN > PORT_PIN_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
        TOGGLE_BIT (*Lat_registers[pin_config->PORT] , pin_config->PIN) ; 
    
    }
    
    
    return (ret) ;
}
#endif
/**
 * 
 * @param pin_config
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_PIN_CONFIGRATION == CONFIG_ENABLE 

STD_ReturnType gpio_pin_intialize(const pin_config_t * pin_config){
    
    STD_ReturnType ret = E_OK ; 
    if (NULL == pin_config || pin_config->PIN > PORT_PIN_MAX_NUMBER -1 ) {
    
        ret = E_NOT_OK ;
    }
    else 
    {
        ret = gpio_pin_direction_intialize (pin_config) ;
        ret = gpio_pin_write_logic (pin_config , pin_config->LOGIC) ;
    }

    return ret ;
}
#endif
/*****************************************************************************************************************++*/
/**
 * 
 * @param port
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully 
 */
#if GPIO_PORT_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_port_direction_intialize(port_index_t port , uint_8 direction){
    
    STD_ReturnType ret = E_OK ;
    if (port > PORT_MAX_NUMBER -1 ){
        ret = E_NOT_OK ;
    
    }
    else {
        *Tris_registers[port] = direction ;
        
    }
    
    
    return (ret) ;


}
#endif
/**
 * 
 * @param port
 * @param direction
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_port_get_direction_status(port_index_t port , uint_8 * direction){
    
    STD_ReturnType ret = E_OK ;
    if((NULL == direction) && (port > PORT_MAX_NUMBER -1 )){
        ret = E_NOT_OK ;
    }
    else {
        
         *Tris_registers[port] = *direction ;
    
    }
    
    
    return (ret) ;

}
#endif
/**
 * 
 * @param port
 * @param logic
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_port_write_logic(port_index_t port , uint_8 logic){
    
    STD_ReturnType ret = E_OK ;
    if (port > PORT_MAX_NUMBER -1 ){
        ret = E_NOT_OK ;
    
    }
    else {
        *Lat_registers[port] = logic ;
        
    }
    
    
    return (ret) ;

}
#endif
/**
 * 
 * @param port
 * @param logic
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_port_Read_logic(port_index_t port , uint_8 * logic){

    STD_ReturnType ret = E_OK ;
    if((NULL == logic) && (port > PORT_MAX_NUMBER -1)){
        ret = E_NOT_OK ;
    }
    else {
     
        *Port_registers[port] = *logic ;
    }
    
    return (ret) ;
}
#endif
/**
 * 
 * @param port
 @return status of the function 
 *    (E_OK) : The function is done successfully
 *    (E_NOT_OK) : The function is not done successfully
 */
#if GPIO_PORT_CONFIGRATION == CONFIG_ENABLE 
STD_ReturnType gpio_port_toggle_logic(port_index_t port ){
    
    STD_ReturnType ret = E_OK ;
     if(port > PORT_MAX_NUMBER -1){
        ret = E_NOT_OK ;
    }
    else {
     
        *Lat_registers[port] = *Lat_registers[port] ^ 0xFF ;
    }
    
    
    return (ret) ;

}
#endif