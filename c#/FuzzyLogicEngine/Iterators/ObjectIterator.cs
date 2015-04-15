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
	public sealed class ObjectIterator <TObject> : IEnumerator < TObject > where TObject : Object
	{
		public ObjectIterator ( Engine referee )
		{
			theReferee = referee;
			theIndex = -1;
		}
		readonly Engine theReferee;
		int theIndex;

		#region IEnumerator implementation
		bool IEnumerator.MoveNext ()
		{
			int tmp = theIndex + 1;
			if (tmp >= theReferee.internals.Count)
				return false;
			while (theReferee.internals [tmp] as TObject == null) {
				tmp++;
				if (tmp >= theReferee.internals.Count)
					return false;
			}
			theIndex = tmp;
			return true;
		}
		void IEnumerator.Reset ()
		{
			theIndex = -1;
		}
		object IEnumerator.Current {
			get {
				if (theIndex < 0)
					throw new ApplicationException("Enumerator not initialized properly");
				return theReferee.internals [theIndex];
			}
		}
		#endregion
		#region IDisposable implementation
		void IDisposable.Dispose ()
		{
			//throw new NotImplementedException ();
		}
		#endregion
		#region IEnumerator implementation
		TObject IEnumerator<TObject>.Current {
			get {
				if (theIndex < 0)
					throw new ApplicationException("Enumerator not initialized properly");
				return (TObject) theReferee.internals [theIndex];
			}
		}
		#endregion
	}
	public sealed class IndirectObjectIterator <TObject> : IEnumerator < TObject > where TObject : Object
	{
		public IndirectObjectIterator ( Engine referee, List < int > elements )
		{
			theReferee = referee;
			theElements = elements;
			theIndex = -1;
		}
		readonly Engine theReferee;
		readonly List < int > theElements;
		int theIndex;

		#region IEnumerator implementation
		bool IEnumerator.MoveNext ()
		{
			int tmp = theIndex + 1;
			if (tmp >= theElements.Count)
				return false;
			theIndex = tmp;
			return true;
		}
		void IEnumerator.Reset ()
		{
			theIndex = -1;
		}
		object IEnumerator.Current {
			get {
				if (theIndex < 0)
					throw new ApplicationException("Enumerator not initialized properly");
				return theReferee.internals [theElements[theIndex]];
			}
		}
		#endregion
		#region IDisposable implementation
		void IDisposable.Dispose ()
		{
			//throw new NotImplementedException ();
		}
		#endregion
		#region IEnumerator implementation
		TObject IEnumerator<TObject>.Current {
			get {
				if (theIndex < 0)
					throw new ApplicationException("Enumerator not initialized properly");
				return (TObject) theReferee.internals [theElements[theIndex]];
			}
		}
		#endregion
	}
}

