/** function to draw line */
void draw_line (float ax, float ay, float bx, float by)  /** ax,ay = initial points, bx,by = final points */
{  
  int dx = abs (bx - ax);   /**to know slope of line */
 
  int dy = abs (by - ay);  
  int x, y;  
  
  if (dx >= dy)   /** if slope of line <1 */
  {  
   int d = 2*dy-dx; /** updating factor to check position of next mid point wrt line */
    
   int ds = 2*dy;  
   int dt = 2*(dy-dx);  
   if (ax < bx) /** check if it has reached till final x limit */
   {  
       x = ax;  
       y = ay;  
   }  
   else  
   {   
       x = bx;  
       y = by;  
       bx = ax;  
       by = ay;  
   }  
   plot(x, y);      /** plot function to mark pixel */
   
   while (x < bx)        /** loop to run till final x */
   {  
        if (d < 0)  
       d += ds;  
       else 
       {  
       /** check it if has reached till final y limit or not */
           if (y < by) 
           {  
             y++;  
              d += dt;  
           }   
           else 
           {  
             y--;  
             d += dt;  
           }  
       }  
        x++;  
  /** plot function to mark pixel */
       plot(x, y);  
    }  
  }       
  /** slope > 1 line below */
  else {   
            int d = 2*dx-dy;  
            int ds = 2*dx;  
            int dt = 2*(dx-dy);  
            /** to check if reached till final y limit or not */
            if (ay < by) {  
            x = ax;  
            y = ay;  
             }  
             else {   
             x = bx;  
             y = by;  
             by = ay;  
             bx = ax;  
            }  
            /** plot function to mark pixel */
            plot(x, y);
            /** loop to run till final y */
        while (y < by)  
        {  
              if (d < 0)  
                 d += ds;  
              else 
              {  
                 if (x > bx)
                 {  
                     x--;  
                     d += dt;  
                 } 
                 else 
                 {  
                     x++;  
                     d += dt;  
                 }  
              }  
             y++;  
             plot(x, y);  /** plot function to mark pixel */
        }  
    }  
 }  


/*void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);			// set line color
	glPointSize(4.0);				// thickness of line
	draw_line(ax,ay,bx,by);
	glFlush();
}
*/

