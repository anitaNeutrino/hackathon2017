/* 
 * Macro to run Magic Display (very simple!)
 *
 */
#include "AnitaVersion.h"

void doMagicDisplay(int run=2017)
{
  AnitaVersion::set(3); //because MagicDisplay loads filters at the start

  MagicDisplay * magic = new MagicDisplay(run); 
  magic->startEventDisplay(); 
}
