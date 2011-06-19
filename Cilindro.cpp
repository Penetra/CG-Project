int Cylinder::intersection(Ray &ray, double &t) {

    t = DBL_MAX;

    Vector ro;
    ro.x = top.x;
    ro.y = top.y - height / 2;
    ro.z = top.z;
    Vector pvt_center;
    
    pvt_center.x = ro.x;
    pvt_center.y = ro.y;
    pvt_center.z = ro.z;
    
    
    ro.x = ro.x - ray.start.x;
    ro.y = ro.y - ray.start.y;
    ro.z = ro.z - ray.start.z;
    Vector Rd = ray.direction;



    double a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
    double b = ro.x * ray.direction.x + ro.z * ray.direction.z;
    double c = ro.x * ro.x + ro.z * ro.z - raio2;

    double disc = b * b - a*c;

    double oldroot = t, d, root1, root2;

    int return_value = 0;

    if (disc > 0.0) {
        d = sqrtf(disc);
        root2 = (b + d) / a;
        root1 = (b - d) / a;
        // If root2 < 0, then root1 is also < 0, so they are both misses.
        if (root2 > 0) {
            // If root2 > 0, and root1 < 0, we are inside the cylinder.
            if (root1 < 0) {
                if (root2 < t) {
                    t = root2;
                    return_value = -1;
                }
                // If root2 > 0, and root1 > 0, we are hit the cylinder.
            } else {
                if (root1 < t) {
                    t = root1;
                    return_value = 1;
                }
            }
        }


        Point pnt_intrsct = ray.start + Rd* t;
        if ((pnt_intrsct.y > top.y) || (pnt_intrsct.y < bottom.y)) {
            pnt_intrsct = ray.start + Rd*root2;
            // Are we too high in our first hit, but hit the back wall later
            if ((pnt_intrsct.y > top.y) || (pnt_intrsct.y < bottom.y)) {
                t = oldroot;
                return_value = 0;
            }
        }
        Point Ro = ray.start;
        if (Rd.y != 0.) {
            // check top cap
            root1 = -(Ro.y - top.y) / Rd.y;
            if (root1 > 0.0f) {
                pnt_intrsct = ray.start + Rd * root1 - pvt_center;
                if (pnt_intrsct.x * pnt_intrsct.x + pnt_intrsct.z * pnt_intrsct.z <= raio2) {
                    if (root1 < oldroot) {
                        t = root1;
                        return_value = 1;
                    }
                }
            }
            // check bottom cap
            root2 = -(Ro.y - bottom.y) / Rd.y;
            if (root2 > 0.0f) {
                pnt_intrsct = ray.start + Rd * root2 - pvt_center;
                if (pnt_intrsct.x * pnt_intrsct.x + pnt_intrsct.z * pnt_intrsct.z <= raio2) {
                    if ((root2 < root1) && (root2 < oldroot)) {
                        t = root2;
                        return_value = 1;
                    }
                }
            }
        }


    }
    return return_value;
}