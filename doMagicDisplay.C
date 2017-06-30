/* 
 * Macro to run Magic Display (very simple!)
 *
 */
#include "AnitaVersion.h"


void doMagicDisplay(int run=2017)
{
  AnitaVersion::set(3);

  MagicDisplay * magic = new MagicDisplay(run); 
  magic->startEventDisplay(); 
}
