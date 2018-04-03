/*****************************************************************************
 *
 * Eltex Meteo Project
 *
 * Copyright (C) 2018 Sergey Denisov.
 * Written by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public Licence 3
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 *
 *****************************************************************************/

package com.denfnd.utils;


import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;


public class MutexLocker implements Locker {
    private Map<String, ReadWriteLock> mutexs = new HashMap<>();

    public void addMutex(String name) {
        mutexs.put(name, new ReentrantReadWriteLock());
    }

    public void lockRead(String name) {
        mutexs.get(name).readLock().lock();
    }

    public void unlockRead(String name) {
        mutexs.get(name).readLock().unlock();
    }

    public void lockWrite(String name) {
        mutexs.get(name).writeLock().lock();
    }

    public void unlockWrite(String name) {
        mutexs.get(name).writeLock().unlock();
    }
}
