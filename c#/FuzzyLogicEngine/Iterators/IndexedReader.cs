﻿// ------------------------------------------------------------------------------
//  <autogenerated>
//      This code was generated by a tool.
//      Mono Runtime Version: 4.0.30319.1
// 
//      Changes to this file may cause incorrect behavior and will be lost if 
//      the code is regenerated.
//  </autogenerated>
// ------------------------------------------------------------------------------
using System;
using System.Collections;
using System.Collections.Generic;

using FuzzyLogic;

namespace FuzzyLogic
{
	public class IndexedReader<I,T> {
		private Func<I,T> getter;

		public IndexedReader(Func<I, T> g)
		{
			if (g == null)
				throw new ArgumentNullException();
			getter = g;
		}

		public T this[I index]
		{
			get
			{
				return getter(index);
			}
		}
	}
}

