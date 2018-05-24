class GameStats():
    def __init__(self,ai_settings):
        self.ai_settings  = ai_settings
        self.game_active = False
        self.reset_stats()


    def reset_stats(self):
        if not self.game_active:
            self.ships_left = self.ai_settings.ship_limit




