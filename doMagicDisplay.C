/* 
 * Macro to run Magic Display (very simple!)
 *
 */

void doMagicDisplay(int run=2017)
{
  MagicDisplay * magic = new MagicDisplay(run); 
  magic->startEventDisplay(); 
}
