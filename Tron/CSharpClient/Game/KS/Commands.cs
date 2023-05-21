using System;
using System.Linq;
using System.Collections.Generic;

namespace KS.Commands
{
	public enum ECommandDirection
	{
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3,
	}
	
	public partial class ChangeDirection : KSObject
	{
		public ECommandDirection? Direction { get; set; }
		

		public ChangeDirection()
		{
		}
		
		public new const string NameStatic = "ChangeDirection";
		
		public override string Name() => "ChangeDirection";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize Direction
			s.Add((byte)((Direction == null) ? 0 : 1));
			if (Direction != null)
			{
				s.Add((byte)((sbyte)Direction));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize Direction
			byte tmp0;
			tmp0 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp0 == 1)
			{
				sbyte tmp1;
				tmp1 = (sbyte)s[(int)offset];
				offset += sizeof(sbyte);
				Direction = (ECommandDirection)tmp1;
			}
			else
				Direction = null;
			
			return offset;
		}
	}
	
	public partial class ActivateWallBreaker : KSObject
	{
		

		public ActivateWallBreaker()
		{
		}
		
		public new const string NameStatic = "ActivateWallBreaker";
		
		public override string Name() => "ActivateWallBreaker";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			return offset;
		}
	}
} // namespace KS.Commands
