using System;
using System.Linq;
using System.Collections.Generic;

namespace KS.Models
{
	public enum ECell
	{
		Empty = 0,
		AreaWall = 1,
		BlueWall = 2,
		YellowWall = 3,
	}
	
	public enum EDirection
	{
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3,
	}
	
	public partial class Constants : KSObject
	{
		public int? MaxCycles { get; set; }
		public int? InitHealth { get; set; }
		public int? WallBreakerCooldown { get; set; }
		public int? WallBreakerDuration { get; set; }
		public int? WallScoreCoefficient { get; set; }
		public int? AreaWallCrashScore { get; set; }
		public int? MyWallCrashScore { get; set; }
		public int? EnemyWallCrashScore { get; set; }
		

		public Constants()
		{
		}
		
		public new const string NameStatic = "Constants";
		
		public override string Name() => "Constants";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize MaxCycles
			s.Add((byte)((MaxCycles == null) ? 0 : 1));
			if (MaxCycles != null)
			{
				s.AddRange(BitConverter.GetBytes((int)MaxCycles));
			}
			
			// serialize InitHealth
			s.Add((byte)((InitHealth == null) ? 0 : 1));
			if (InitHealth != null)
			{
				s.AddRange(BitConverter.GetBytes((int)InitHealth));
			}
			
			// serialize WallBreakerCooldown
			s.Add((byte)((WallBreakerCooldown == null) ? 0 : 1));
			if (WallBreakerCooldown != null)
			{
				s.AddRange(BitConverter.GetBytes((int)WallBreakerCooldown));
			}
			
			// serialize WallBreakerDuration
			s.Add((byte)((WallBreakerDuration == null) ? 0 : 1));
			if (WallBreakerDuration != null)
			{
				s.AddRange(BitConverter.GetBytes((int)WallBreakerDuration));
			}
			
			// serialize WallScoreCoefficient
			s.Add((byte)((WallScoreCoefficient == null) ? 0 : 1));
			if (WallScoreCoefficient != null)
			{
				s.AddRange(BitConverter.GetBytes((int)WallScoreCoefficient));
			}
			
			// serialize AreaWallCrashScore
			s.Add((byte)((AreaWallCrashScore == null) ? 0 : 1));
			if (AreaWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)AreaWallCrashScore));
			}
			
			// serialize MyWallCrashScore
			s.Add((byte)((MyWallCrashScore == null) ? 0 : 1));
			if (MyWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)MyWallCrashScore));
			}
			
			// serialize EnemyWallCrashScore
			s.Add((byte)((EnemyWallCrashScore == null) ? 0 : 1));
			if (EnemyWallCrashScore != null)
			{
				s.AddRange(BitConverter.GetBytes((int)EnemyWallCrashScore));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize MaxCycles
			byte tmp0;
			tmp0 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp0 == 1)
			{
				MaxCycles = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				MaxCycles = null;
			
			// deserialize InitHealth
			byte tmp1;
			tmp1 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp1 == 1)
			{
				InitHealth = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				InitHealth = null;
			
			// deserialize WallBreakerCooldown
			byte tmp2;
			tmp2 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp2 == 1)
			{
				WallBreakerCooldown = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				WallBreakerCooldown = null;
			
			// deserialize WallBreakerDuration
			byte tmp3;
			tmp3 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp3 == 1)
			{
				WallBreakerDuration = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				WallBreakerDuration = null;
			
			// deserialize WallScoreCoefficient
			byte tmp4;
			tmp4 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp4 == 1)
			{
				WallScoreCoefficient = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				WallScoreCoefficient = null;
			
			// deserialize AreaWallCrashScore
			byte tmp5;
			tmp5 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp5 == 1)
			{
				AreaWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				AreaWallCrashScore = null;
			
			// deserialize MyWallCrashScore
			byte tmp6;
			tmp6 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp6 == 1)
			{
				MyWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				MyWallCrashScore = null;
			
			// deserialize EnemyWallCrashScore
			byte tmp7;
			tmp7 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp7 == 1)
			{
				EnemyWallCrashScore = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				EnemyWallCrashScore = null;
			
			return offset;
		}
	}
	
	public partial class Position : KSObject
	{
		public int? X { get; set; }
		public int? Y { get; set; }
		

		public Position()
		{
		}
		
		public new const string NameStatic = "Position";
		
		public override string Name() => "Position";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize X
			s.Add((byte)((X == null) ? 0 : 1));
			if (X != null)
			{
				s.AddRange(BitConverter.GetBytes((int)X));
			}
			
			// serialize Y
			s.Add((byte)((Y == null) ? 0 : 1));
			if (Y != null)
			{
				s.AddRange(BitConverter.GetBytes((int)Y));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize X
			byte tmp8;
			tmp8 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp8 == 1)
			{
				X = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				X = null;
			
			// deserialize Y
			byte tmp9;
			tmp9 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp9 == 1)
			{
				Y = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				Y = null;
			
			return offset;
		}
	}
	
	public partial class Agent : KSObject
	{
		public int? Health { get; set; }
		public Position Position { get; set; }
		public EDirection? Direction { get; set; }
		public int? WallBreakerCooldown { get; set; }
		public int? WallBreakerRemTime { get; set; }
		

		public Agent()
		{
		}
		
		public new const string NameStatic = "Agent";
		
		public override string Name() => "Agent";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize Health
			s.Add((byte)((Health == null) ? 0 : 1));
			if (Health != null)
			{
				s.AddRange(BitConverter.GetBytes((int)Health));
			}
			
			// serialize Position
			s.Add((byte)((Position == null) ? 0 : 1));
			if (Position != null)
			{
				s.AddRange(Position.Serialize());
			}
			
			// serialize Direction
			s.Add((byte)((Direction == null) ? 0 : 1));
			if (Direction != null)
			{
				s.Add((byte)((sbyte)Direction));
			}
			
			// serialize WallBreakerCooldown
			s.Add((byte)((WallBreakerCooldown == null) ? 0 : 1));
			if (WallBreakerCooldown != null)
			{
				s.AddRange(BitConverter.GetBytes((int)WallBreakerCooldown));
			}
			
			// serialize WallBreakerRemTime
			s.Add((byte)((WallBreakerRemTime == null) ? 0 : 1));
			if (WallBreakerRemTime != null)
			{
				s.AddRange(BitConverter.GetBytes((int)WallBreakerRemTime));
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize Health
			byte tmp10;
			tmp10 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp10 == 1)
			{
				Health = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				Health = null;
			
			// deserialize Position
			byte tmp11;
			tmp11 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp11 == 1)
			{
				Position = new Position();
				offset = Position.Deserialize(s, offset);
			}
			else
				Position = null;
			
			// deserialize Direction
			byte tmp12;
			tmp12 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp12 == 1)
			{
				sbyte tmp13;
				tmp13 = (sbyte)s[(int)offset];
				offset += sizeof(sbyte);
				Direction = (EDirection)tmp13;
			}
			else
				Direction = null;
			
			// deserialize WallBreakerCooldown
			byte tmp14;
			tmp14 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp14 == 1)
			{
				WallBreakerCooldown = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				WallBreakerCooldown = null;
			
			// deserialize WallBreakerRemTime
			byte tmp15;
			tmp15 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp15 == 1)
			{
				WallBreakerRemTime = BitConverter.ToInt32(s, (int)offset);
				offset += sizeof(int);
			}
			else
				WallBreakerRemTime = null;
			
			return offset;
		}
	}
	
	public partial class World : KSObject
	{
		public List<List<ECell?>> Board { get; set; }
		public Dictionary<string, Agent> Agents { get; set; }
		public Dictionary<string, int?> Scores { get; set; }
		public Constants Constants { get; set; }
		

		public World()
		{
		}
		
		public new const string NameStatic = "World";
		
		public override string Name() => "World";
		
		public override byte[] Serialize()
		{
			List<byte> s = new List<byte>();
			
			// serialize Board
			s.Add((byte)((Board == null) ? 0 : 1));
			if (Board != null)
			{
				List<byte> tmp16 = new List<byte>();
				tmp16.AddRange(BitConverter.GetBytes((uint)Board.Count()));
				while (tmp16.Count > 0 && tmp16.Last() == 0)
					tmp16.RemoveAt(tmp16.Count - 1);
				s.Add((byte)tmp16.Count);
				s.AddRange(tmp16);
				
				foreach (var tmp17 in Board)
				{
					s.Add((byte)((tmp17 == null) ? 0 : 1));
					if (tmp17 != null)
					{
						List<byte> tmp18 = new List<byte>();
						tmp18.AddRange(BitConverter.GetBytes((uint)tmp17.Count()));
						while (tmp18.Count > 0 && tmp18.Last() == 0)
							tmp18.RemoveAt(tmp18.Count - 1);
						s.Add((byte)tmp18.Count);
						s.AddRange(tmp18);
						
						foreach (var tmp19 in tmp17)
						{
							s.Add((byte)((tmp19 == null) ? 0 : 1));
							if (tmp19 != null)
							{
								s.Add((byte)((sbyte)tmp19));
							}
						}
					}
				}
			}
			
			// serialize Agents
			s.Add((byte)((Agents == null) ? 0 : 1));
			if (Agents != null)
			{
				List<byte> tmp20 = new List<byte>();
				tmp20.AddRange(BitConverter.GetBytes((uint)Agents.Count()));
				while (tmp20.Count > 0 && tmp20.Last() == 0)
					tmp20.RemoveAt(tmp20.Count - 1);
				s.Add((byte)tmp20.Count);
				s.AddRange(tmp20);
				
				foreach (var tmp21 in Agents)
				{
					s.Add((byte)((tmp21.Key == null) ? 0 : 1));
					if (tmp21.Key != null)
					{
						List<byte> tmp22 = new List<byte>();
						tmp22.AddRange(BitConverter.GetBytes((uint)tmp21.Key.Count()));
						while (tmp22.Count > 0 && tmp22.Last() == 0)
							tmp22.RemoveAt(tmp22.Count - 1);
						s.Add((byte)tmp22.Count);
						s.AddRange(tmp22);
						
						s.AddRange(System.Text.Encoding.GetEncoding("ISO-8859-1").GetBytes(tmp21.Key));
					}
					
					s.Add((byte)((tmp21.Value == null) ? 0 : 1));
					if (tmp21.Value != null)
					{
						s.AddRange(tmp21.Value.Serialize());
					}
				}
			}
			
			// serialize Scores
			s.Add((byte)((Scores == null) ? 0 : 1));
			if (Scores != null)
			{
				List<byte> tmp23 = new List<byte>();
				tmp23.AddRange(BitConverter.GetBytes((uint)Scores.Count()));
				while (tmp23.Count > 0 && tmp23.Last() == 0)
					tmp23.RemoveAt(tmp23.Count - 1);
				s.Add((byte)tmp23.Count);
				s.AddRange(tmp23);
				
				foreach (var tmp24 in Scores)
				{
					s.Add((byte)((tmp24.Key == null) ? 0 : 1));
					if (tmp24.Key != null)
					{
						List<byte> tmp25 = new List<byte>();
						tmp25.AddRange(BitConverter.GetBytes((uint)tmp24.Key.Count()));
						while (tmp25.Count > 0 && tmp25.Last() == 0)
							tmp25.RemoveAt(tmp25.Count - 1);
						s.Add((byte)tmp25.Count);
						s.AddRange(tmp25);
						
						s.AddRange(System.Text.Encoding.GetEncoding("ISO-8859-1").GetBytes(tmp24.Key));
					}
					
					s.Add((byte)((tmp24.Value == null) ? 0 : 1));
					if (tmp24.Value != null)
					{
						s.AddRange(BitConverter.GetBytes((int)tmp24.Value));
					}
				}
			}
			
			// serialize Constants
			s.Add((byte)((Constants == null) ? 0 : 1));
			if (Constants != null)
			{
				s.AddRange(Constants.Serialize());
			}
			
			return s.ToArray();
		}
		
		public override uint Deserialize(byte[] s, uint offset = 0)
		{
			// deserialize Board
			byte tmp26;
			tmp26 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp26 == 1)
			{
				byte tmp27;
				tmp27 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp28 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp28, 0, tmp27);
				offset += tmp27;
				uint tmp29;
				tmp29 = BitConverter.ToUInt32(tmp28, (int)0);
				
				Board = new List<List<ECell?>>();
				for (uint tmp30 = 0; tmp30 < tmp29; tmp30++)
				{
					List<ECell?> tmp31;
					byte tmp32;
					tmp32 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp32 == 1)
					{
						byte tmp33;
						tmp33 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp34 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp34, 0, tmp33);
						offset += tmp33;
						uint tmp35;
						tmp35 = BitConverter.ToUInt32(tmp34, (int)0);
						
						tmp31 = new List<ECell?>();
						for (uint tmp36 = 0; tmp36 < tmp35; tmp36++)
						{
							ECell? tmp37;
							byte tmp38;
							tmp38 = (byte)s[(int)offset];
							offset += sizeof(byte);
							if (tmp38 == 1)
							{
								sbyte tmp39;
								tmp39 = (sbyte)s[(int)offset];
								offset += sizeof(sbyte);
								tmp37 = (ECell)tmp39;
							}
							else
								tmp37 = null;
							tmp31.Add(tmp37);
						}
					}
					else
						tmp31 = null;
					Board.Add(tmp31);
				}
			}
			else
				Board = null;
			
			// deserialize Agents
			byte tmp40;
			tmp40 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp40 == 1)
			{
				byte tmp41;
				tmp41 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp42 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp42, 0, tmp41);
				offset += tmp41;
				uint tmp43;
				tmp43 = BitConverter.ToUInt32(tmp42, (int)0);
				
				Agents = new Dictionary<string, Agent>();
				for (uint tmp44 = 0; tmp44 < tmp43; tmp44++)
				{
					string tmp45;
					byte tmp47;
					tmp47 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp47 == 1)
					{
						byte tmp48;
						tmp48 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp49 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp49, 0, tmp48);
						offset += tmp48;
						uint tmp50;
						tmp50 = BitConverter.ToUInt32(tmp49, (int)0);
						
						tmp45 = System.Text.Encoding.GetEncoding("ISO-8859-1").GetString(s.Skip((int)offset).Take((int)tmp50).ToArray());
						offset += tmp50;
					}
					else
						tmp45 = null;
					
					Agent tmp46;
					byte tmp51;
					tmp51 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp51 == 1)
					{
						tmp46 = new Agent();
						offset = tmp46.Deserialize(s, offset);
					}
					else
						tmp46 = null;
					
					Agents[tmp45] = tmp46;
				}
			}
			else
				Agents = null;
			
			// deserialize Scores
			byte tmp52;
			tmp52 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp52 == 1)
			{
				byte tmp53;
				tmp53 = (byte)s[(int)offset];
				offset += sizeof(byte);
				byte[] tmp54 = new byte[sizeof(uint)];
				Array.Copy(s, offset, tmp54, 0, tmp53);
				offset += tmp53;
				uint tmp55;
				tmp55 = BitConverter.ToUInt32(tmp54, (int)0);
				
				Scores = new Dictionary<string, int?>();
				for (uint tmp56 = 0; tmp56 < tmp55; tmp56++)
				{
					string tmp57;
					byte tmp59;
					tmp59 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp59 == 1)
					{
						byte tmp60;
						tmp60 = (byte)s[(int)offset];
						offset += sizeof(byte);
						byte[] tmp61 = new byte[sizeof(uint)];
						Array.Copy(s, offset, tmp61, 0, tmp60);
						offset += tmp60;
						uint tmp62;
						tmp62 = BitConverter.ToUInt32(tmp61, (int)0);
						
						tmp57 = System.Text.Encoding.GetEncoding("ISO-8859-1").GetString(s.Skip((int)offset).Take((int)tmp62).ToArray());
						offset += tmp62;
					}
					else
						tmp57 = null;
					
					int? tmp58;
					byte tmp63;
					tmp63 = (byte)s[(int)offset];
					offset += sizeof(byte);
					if (tmp63 == 1)
					{
						tmp58 = BitConverter.ToInt32(s, (int)offset);
						offset += sizeof(int);
					}
					else
						tmp58 = null;
					
					Scores[tmp57] = tmp58;
				}
			}
			else
				Scores = null;
			
			// deserialize Constants
			byte tmp64;
			tmp64 = (byte)s[(int)offset];
			offset += sizeof(byte);
			if (tmp64 == 1)
			{
				Constants = new Constants();
				offset = Constants.Deserialize(s, offset);
			}
			else
				Constants = null;
			
			return offset;
		}
	}
} // namespace KS.Models
