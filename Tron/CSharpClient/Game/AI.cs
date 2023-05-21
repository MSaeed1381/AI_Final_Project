using System;
using System.Collections.Generic;

using KoalaTeam.Chillin.Client;
using KS;
using KS.Commands;
using KS.Models;

using KSObject = KS.KSObject;

namespace Game
{
	public class AI : RealtimeAI<World, KSObject>
	{
		private readonly Random random = new Random();
		private int stage = 0;

		public AI(World world) : base(world)
		{
		}

		public override void Initialize()
		{
			Console.WriteLine("initialize");
		}

		public override void Decide()
		{
			Console.WriteLine("decide");

			ChangeDirection((EDirection)random.Next(Enum.GetNames(typeof(EDirection)).Length));
			if (this.World.Agents[this.MySide].WallBreakerCooldown == 0)
				ActivateWallBreaker();
		}


		public void ChangeDirection(EDirection direction)
		{
			this.SendCommand(new ChangeDirection() { Direction = (ECommandDirection?)direction });
		}

		public void ActivateWallBreaker()
		{
			this.SendCommand(new ActivateWallBreaker());
		}
	}
}
